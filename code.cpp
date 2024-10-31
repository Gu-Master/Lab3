
sequence1 = randi([-10, 10], 1, 20);
sequence2 = randi([-10, 10], 1, 20);
sequence3 = randi([-10, 10], 1, 20);
sequence4 = randi([-10, 10], 1, 20);


[acf1, lags1] = xcorr(sequence1, 'coeff');
[acf2, lags2] = xcorr(sequence2, 'coeff');
[acf3, lags3] = xcorr(sequence3, 'coeff');
[acf4, lags4] = xcorr(sequence4, 'coeff');


figure;
plot(lags1, acf1, '-o', 'DisplayName', 'Sequence 1'); hold on;
plot(lags2, acf2, '-x', 'DisplayName', 'Sequence 2');
plot(lags3, acf3, '-s', 'DisplayName', 'Sequence 3');
plot(lags4, acf4, '-d', 'DisplayName', 'Sequence 4');

title('Autocorrelation of Four Sequences');
xlabel('Lag');
ylabel('Autocorrelation');
legend;
grid on;
hold off;


second_max_vals = zeros(1, 4);
for i = 1:4
    acf = eval(['acf', num2str(i)]); 
    acf_sorted = sort(abs(acf), 'descend');
    second_max_vals(i) = acf_sorted(2); 
end


[~, best_idx] = max(second_max_vals);
[~, worst_idx] = min(second_max_vals);


fprintf('Худшая последовательность для синхронизации: Sequence %d (второе максимальное значение = %.4f)\n', best_idx, second_max_vals(best_idx));
fprintf('Л последовательность для синхронизации: Sequence %d (второе максимальное значение = %.4f)\n', worst_idx, second_max_vals(worst_idx));
