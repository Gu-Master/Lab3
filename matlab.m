% Исходные массивы данных
a = [4, 2, 8, -2, -4, -4, 1, 3];
b = [2, 1, 5, 0, -2, -3, 2, 4];
c = [-4, -1, -3, 1, 2, 5, -1, -2];

% 1. Вычисление корреляции между массивами a, b и c
corr_ab = corr(a', b');
corr_ac = corr(a', c');
corr_bc = corr(b', c');

% 2. Время для сигналов
t = 0:0.01:1;

% Сигналы для анализа корреляции
s1 = sin(2 * pi * 5 * t); % Пример сигнала s1(t)
b_extended = interp1(1:length(b), b, linspace(1, length(b), length(t)), 'linear', 'extrap');

% 3. Определение корреляции между s1(t) и массивами a и b
corr_s1_a = corr(s1', interp1(1:length(a), a, linspace(1, length(a), length(s1)))');
corr_s1_b = corr(s1', b_extended');

% Вывод корреляции между s1(t) и a, b
disp(['Корреляция между s1 и a: ', num2str(corr_s1_a)]);
disp(['Корреляция между s1 и b: ', num2str(corr_s1_b)]);

% 4. Графики массивов a и b
figure;
subplot(2, 1, 1);
plot(a, 'o-');
title('Массив a');
xlabel('Индекс');
ylabel('Значение');

subplot(2, 1, 2);
plot(b, 'o-');
title('Массив b');
xlabel('Индекс');
ylabel('Значение');

% 5. Вычисление взаимной корреляции со сдвигом для массивов a и b
max_corr = -Inf;
best_shift = 0;
num_shifts = length(a);
correlations = zeros(1, num_shifts);

for shift = 0:num_shifts-1
    b_shifted = [zeros(1, shift), b(1:end-shift)]; % Сдвиг b вправо
    corr_value = corr(a', b_shifted');
    correlations(shift + 1) = corr_value;

    if corr_value > max_corr
        max_corr = corr_value;
        best_shift = shift;
    end
end

% Показать результаты корреляции
disp(['Максимальная корреляция: ', num2str(max_corr), ' при сдвиге ', num2str(best_shift)]);

% Построение графика корреляции в зависимости от сдвига
figure;
plot(0:num_shifts-1, correlations, '-o');
title('Взаимная корреляция последовательностей от величины сдвига');
xlabel('Сдвиг');
ylabel('Корреляция');

% Построение графиков a и b со сдвигом для максимальной корреляции
figure;
subplot(2, 1, 1);
plot(a, 'o-');
title('Массив a');
xlabel('Индекс');
ylabel('Значение');

subplot(2, 1, 2);
plot([zeros(1, best_shift), b(1:end-best_shift)], 'o-');
title(['Массив b, сдвинутый на ', num2str(best_shift)]);
xlabel('Индекс');
ylabel('Значение');
