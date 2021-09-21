import random

VALID_PUNCTUATION = ['?', '.', '!', ',', ':', ';']
END_OF_SENTENCE_PUNCTUATION = ['?', '.', '!']
ALWAYS_CAPITALIZE = ["I", "Montmorency", "George", "Harris", "J", "London", "Thames", "Liverpool", "Flatland", "", "Mrs", "Ms", "Mr", "William", "Samuel"]
BAD_CHARS = ['"', "(", ")", "{", "}", "[", "]", "_"]


def check_open_ngram(current_ngram, ngram_model):
    """
    (tup, Dict{tup: List[List[int]]}) -> Bool

    Checks the current value associated with the n-gram key
    in ngram_model. Returns True for non-empty list,
    False for an empty list of tokens that follow it.

    check_open_ngram assumes that current_ngram exists as a
    key in ngram_model.
    """
    return not ngram_model[current_ngram][0] == []


def gen_seed(ngram_model):
    """
    (Dict{tup: List[List[int]]}) -> tup

    Returns a tuple of length n by selecting a random n-gram from the
    keys of the ngram_model. You are guaranteed that the generated
    seed (i.e. tuple) will contain no punctuation.

    The function assumes that there is at least one tuple without punctuation that
    has a non-empty list of words associated with it.
    """
    ngram_model_key_list = sorted(list(ngram_model))  # sort for repeatability
    ngram = random.choice(ngram_model_key_list)

    punc_in_ngram = False
    for item in ngram:
        if item in VALID_PUNCTUATION:
            punc_in_ngram = True

    while not check_open_ngram(ngram, ngram_model) or punc_in_ngram:
        ngram = random.choice(ngram_model_key_list)

        punc_in_ngram = False
        for item in ngram:
            if item in VALID_PUNCTUATION:
                punc_in_ngram = True

    return ngram


def gen_next_token(current_ngram, ngram_model):
    """
    (tup, Dict{tup: List[List[int]]}) -> str

    Randomly generates the next token from the current_ngram based on the
    frequency of each word stored in ngram_model by sampling from the
    distribution of possible next words.

    The function assumes that check_open_ngram(ngram_model, current_ngram) is True,
    i.e. that the array of words corresponding to ngram_model[current_ngram]
    is not empty. The function also assumes that current_ngram is in ngram_model.
    """
    curr_prob = random.random()
    prob_to_index = 0

    words = ngram_model[current_ngram][0]
    # create a copy that the code below does not modify the ngram model
    # Note: shallow copy is sufficient for a list of numbers
    cdf = ngram_model[current_ngram][1].copy()

    for i in range(1, len(cdf)):
        cdf[i] += cdf[i - 1]

    while cdf[prob_to_index] < curr_prob:
        prob_to_index += 1

    return words[prob_to_index]


def parse_story(file_name):
    """
    (file) --> list

    The function reads a file line by line, does string manipulation to every line in order to fit the desired string
    and returns a list that contains the string after it has been split:

    >> parse_story("test_text_parsing.txt")
    ['the', 'code', 'should', 'handle', 'correctly', 'the', 'following', ':',
    'white', 'space', '.', 'sequences', 'of', 'punctuation', 'marks', '?', '!', '!', 'periods', 'with', 'or',
    'without', 'spaces', ':', 'a', '.', '.', 'a', '.', 'a', "don't", 'worry', 'about', 'numbers', 'like', '1', '.',
    '5', 'remove', 'capitalization']
    """
    file = open(file_name, "r")
    parsed_list = []
    parsed_content = ""
    for line in file:
        if line != "\n":
            parsed_content += line.lower().strip(" ")
            parsed_list = parsed_content.split()
    temp_string = ""
    for i in range(len(parsed_list)):
        temp_string += parsed_list[i] + " "
    for i in range(len(VALID_PUNCTUATION)):
        temp_string = temp_string.replace(VALID_PUNCTUATION[i], " " + VALID_PUNCTUATION[i] + " ")
    for i in range(len(BAD_CHARS)):
        temp_string = temp_string.replace(BAD_CHARS[i], "")
    final_list = temp_string.split()
    file.close()
    return final_list


def get_prob_from_count(counts):
    """
    (list) --> list

    The function takes a list of integer numbers, and divides each element by the sum of the list to return a
    probability.

    >> get_prob_from_count([1, 2, 3])
    [0.1666, 0.3333, 0.5]
    """
    s_u_m = sum(counts)
    for i in range(len(counts)):
        counts[i] = counts[i] / s_u_m
    return counts


def build_ngram_counts(words, counts):
    """
    (list, integer) --> dictionary

    The function takes in a list of words, and converts it to grams with length of counts. The function then returns a
    dictionary composed of the grams and the words that follow each gram, as well as the probability of the gram of
    occurring.

    >> build_ngram_counts(['the', 'child', 'will', 'the', 'child', 'can', 'the', 'child', 'can', 'the', 'child',
    'may', 'go', 'home', '.'], 2)

    {('the', 'child'): [['will', 'can', 'may'], [1, 2, 1]], ('child', 'will'): [['the'], [1]], ('will', 'the'): [[
    'child'], [1]], ('child', 'can'): [['the'], [2]], ('can', 'the'): [['child'], [2]], ('child', 'may'): [['go'],
    [1]], ('may', 'go'): [['home'], [1]], ('go', 'home'): [['.'], [1]]}
    """
    dic = {}
    check = []
    next_list = []
    i = 0
    if counts == 1:
        for i in range(len(words) - 1):
            key = tuple([words[i]])
            check.append(key)
        for i in range(len(words) - 1):
            next_list.append([words[i + 1]])
    else:
        while (i < len(words)) and (i + counts < len(words)):
            key = tuple(words[i: i + counts])
            next_word = [words[i + counts]]
            check.append(key)
            next_list.append(next_word)
            i += counts - 1
    count = [x[:] for x in next_list]
    for i in range(len(count)):
        for j in range(len(count[i])):
            count[i][j] = 1
    v = 0
    z = 0
    while z < len(check) and v < len(check):
        if check[v] == check[z] and next_list[v] == next_list[z] and v != z:
            check.pop(z)
            next_list.pop(z)
            count[v][0] += 1
            count.pop(z)
        elif z < len(check) - 1:
            z += 1
        else:
            v += 1
            z = v
    keys = list(check)
    words = [x[:] for x in next_list]
    instances = [x[:] for x in count]
    k = 0
    s = 0
    while k < len(keys) and s < len(keys):
        if keys[k] == keys[s] and k != s:
            keys.pop(s)
            words[k].append(words[s][0])
            words.pop(s)
            instances[k].append(instances[s][0])
            instances.pop(s)
        elif s < len(keys) - 1:
            s += 1
        else:
            k += 1
            s = 0
    for i in range(len(keys)):
        dic[keys[i]] = [words[i], instances[i]]
    return dic


def prune_ngram_counts(ngram_counts, prune_len):
    """
    (dictionary, integer) --> dictionary

    The function takes in a dictionary, and prunes each value. It returns the value list with a length of prune_len.

    >> prune_ngram_counts({('i', 'love'): [['js', 'py3', 'c,'], [20, 20, 10]], ('u', 'r'): [['cool', 'nice', 'lit',
    'kind'], [8, 7, 5, 5]], ('toronto', 'is'): [['six', 'drake'], [2, 3]]}, 2)

    {('i', 'love'): [['js', 'py3'], [20, 20]], ('u', 'r'): [['cool', 'nice'], [8, 7]], ('toronto', 'is'): [['six',
    'drake'], [2, 3]]}
    """
    for key, value in ngram_counts.items():
        word_list = value[0]
        count_list = value[1]
        i = len(count_list) - prune_len
        if len(count_list) > prune_len:
            while i > 0:
                if count_list.count(min(count_list)) > i:
                    i = 0
                else:
                    x = count_list.index(min(count_list))
                    count_list.remove(min(count_list))
                    word_list.pop(x)
                    i -= 1
        ngram_counts[key] = [word_list, count_list]
    return ngram_counts


def probify_ngram_counts(counts):
    """
    (dictionary) --> dictionary

    Probifies the value list in the input dictionary

    >> probify_ngram_counts({('i', 'love'): [['js', 'py3', 'c,'], [20, 20, 10]], ('u', 'r'): [['cool', 'nice', 'lit',
    'kind'], [8, 7, 5, 5]], ('toronto', 'is'): [['six', 'drake'], [2, 3]]})

    {('i', 'love'): [['js', 'py3', 'c,'], [0.4, 0.4, 0.2]], ('u', 'r'): [['cool', 'nice', 'lit', 'kind'], [0.32,
    0.28, 0.2, 0.2]], ('toronto', 'is'): [['six', 'drake'], [0.4, 0.6]]}
    """
    for value in counts.values():
        x = sum(value[1])
        for i in range(len(value[1])):
            value[1][i] = value[1][i] / x
    return counts


def build_ngram_model(words, n):
    """
    (list, integer) --> dictionary

    The function builds a dictionary from a list, prunes, and probifies this dictionary with ngram count value of n
    and a prune length of 15.

    >> build_ngram_model(['the', 'child', 'will', 'the', 'child', 'can', 'the', 'child', 'can', 'the', 'child',
    'may', 'go', 'home', '.'], 2)

    {('the', 'child'): [['can', 'may', 'will'], [0.5, 0.25, 0.25]], ('child', 'will'): [['the'], [1.0]], ('will',
    'the'): [['child'], [1.0]], ('child', 'can'): [['the'], [1.0]], ('can', 'the'): [['child'], [1.0]], ('child',
    'may'): [['go'], [1.0]], ('may', 'go'): [['home'], [1.0]], ('go', 'home'): [['.'], [1.0]]}
    """
    x = build_ngram_counts(words, n)
    y = prune_ngram_counts(x, 15)
    z = probify_ngram_counts(y)
    for key, value in z.items():
        value[0], value[1] = (list(t) for t in zip(*sorted(zip(value[0], value[1]))))
    return z


def gen_bot_list(ngram_model, seed, num_tokens=None):
    """
    (dictionary, tuple, integer) --> list

    The function takes in a dictionary, a particular seed, and a number of tokens and semi randomly generates a list
    that is a sentence starting with the seed, and generating the next word using the gen_next_token function from
    utilities. The list will be num_tokens long.

    >> gen_bot_list({('the', 'child'): [['can', 'may', 'will'], [0.5, 0.25, 0.25]], ('child', 'will'): [['the'],
    [1.0]], ('will', 'the'): [['child'], [1.0]], ('child', 'can'): [['the'], [1.0]], ('can', 'the'): [['child'],
    [1.0]], ('child', 'may'): [['go'], [1.0]], ('may', 'go'): [['home'], [1.0]], ('go', 'home'): [['.'], [1.0]]},
    ("may", "go"), 5)

    ['may', 'go', 'home', '.']
    """
    if num_tokens is None:
        return []
    else:
        sentence = list(seed).copy()
        tup = tuple(seed)
        while len(sentence) < num_tokens:
            if tup not in ngram_model:
                num_tokens = len(sentence)
            else:
                next_word = gen_next_token(tup, ngram_model)
                sentence.append(next_word)
                tup = tuple(sentence[-len(tup):])
        return sentence


def gen_bot_text(token_list, bad_author):
    """
    (list, bool) --> str

    The function takes in a list and a boolean. If the boolean is True, the function returns a string of the list
    separated by a space. Otherwise, the function returns a string that abides by the rules given in lab4v2.

    >> gen_bot(['this', 'is', 'a', 'string', 'of', 'text', '.', 'which', 'george', ',', 'be', 'created', '.'], False)
    "This is a string of text. Which George, be created."
    """
    sentence = ""
    if bad_author:
        for i in range(len(token_list)):
            sentence += token_list[i] + " "
    else:
        token_list[0] = token_list[0].capitalize()
        for i in range(len(token_list)):
            if token_list[i].capitalize() in ALWAYS_CAPITALIZE:
                token_list[i] = token_list[i].capitalize()
        for k in range(len(token_list)):
            if (token_list[k] in END_OF_SENTENCE_PUNCTUATION) and (k + 1 < len(token_list)):
                token_list[k + 1] = token_list[k + 1].capitalize()
        j = 0
        x = len(token_list)
        while j < x:
            if token_list[j] in VALID_PUNCTUATION:
                token_list[j - 1] = token_list[j - 1] + token_list[j]
                token_list.pop(j)
                x -= 1
            j += 1
        for i in range(len(token_list)):
            sentence += token_list[i] + " "
    return sentence


def write_story(file_name, text, title, student_name, author, year):
    """
    (file, str, str, str, str, int) --> file

    The function takes a string and writes it to a file that is then formatted by adding a title page and other
    guidelines listed by lab4v2.

    Examples not applicable here, but the sample file should be the same as the file that is produced by this function
    """
    file = open(file_name, "w+")
    for n in range(10):
        file.write('\n')
    file.write(title + ": " + str(year) + ", UNLEASHED\n")
    file.write(student_name + ", inspired by " + author + "\n")
    file.write("Copyright year published (" + str(year) + "), publisher: EngSci press")
    for n in range(18):
        file.write("\n")
    text = str(text)
    page_number = 1
    chapter_number = 1
    start = 0
    index = 90
    while index < len(text):
        lines = 28
        if (page_number - 1) % 12 == 0:
            file.write("CHAPTER " + str(chapter_number) + "\n\n")
            chapter_number += 1
            lines = 26
        for i in range(lines):
            if text[index] not in (VALID_PUNCTUATION + [" "]):
                if (index < len(text)) and (text[index] not in (VALID_PUNCTUATION + [" "])):
                    while text[index] not in (VALID_PUNCTUATION + [" "]):
                        index -= 1
                else:
                    index += 1
            place_string = text[start: index]
            if len(place_string) == 0:
                break
            file.write(place_string.strip())
            file.write("\n")
            start = index
            index += 90
            if index + 90 > len(text):
                file.write(text[index:])
                file.write("\n")
                index = len(text)
                break
        file.write("\n")
        file.write(str(page_number))
        file.write("\n")
        page_number += 1
    file.close()
