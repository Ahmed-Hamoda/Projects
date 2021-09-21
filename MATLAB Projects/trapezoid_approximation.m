n_vec = 10:100;
trap_approx_vec = zeros(1, length(n_vec));

true_int = 14/3;
K = 1/4;

for i = 1:length(n_vec)
    n = n_vec(i);
    dx = 3/n;
    xbar = 0:dx:3;
    f_at_xbar = sqrt(xbar + 1);
    trap_approx_vec(i) = dx*sum((f_at_xbar(1:end - 1) + f_at_xbar(2:end)) / 2);
end

error_vec = abs(true_int - trap_approx_vec);
errorbound_vec = ((3^3)*(K))./(24*n_vec.^2);
figure
subplot(2, 1, 1)
plot(n_vec, trap_approx_vec, '--b', 'Linewidth', 1.25)
hold on
plot(n_vec, true_int*ones(1, length(n_vec)), '-k', 'Linewidth', 1.25)
legend('Approximation', 'True Value')
title('Trapezoidal Approximation')
xlabel('Number of Intervals (n)')
ylabel('Value')
xlim([0 100])
grid on

subplot(2,1,2)
plot(n_vec, error_vec, '-b', 'Linewidth', 1.25)
hold on
plot(n_vec, errorbound_vec, '--k', 'Linewidth', 1.25)
legend('Absolute Error', 'Error Bound')
xlabel('Number of Intervals (n)')
ylabel('Error')
xlim([0 100])
grid on