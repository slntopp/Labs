# Для проверки использовался двойной интеграл //(4-x^2-y^2)dxdy при пределах -1, 1 для обоих переменных
# При ручном подсчете 13.333333333333334
# ruby csimp.rb "4 - x * x - y * y" -1 1 -1 1 13.333333333333334

require 'progress_bar'

$func, a, b, c, d, manual = ARGV
a, b, c, d, manual = a.to_f, b.to_f, c.to_f, d.to_f, manual.to_f
File.open('math.rb', 'w') { |file| file.write("def exp(t) return Math.exp(t) end \ndef f(x, y = 0) return #{$func} end") }
require './math.rb'

case nil
    when $func
        puts "Отсутствует текст подынтегральной функции!"
        Kernel.exit
    when a
        puts "Отсутствует нижний предел интегрирования!"
        Kernel.exit
    when b
        puts "Отсутствует верхний предел интегрирования!"
        Kernel.exit
    when manual
        puts "Отсутствует значение интеграла при ручном подсчете!"
        Kernel.exit
    else
        puts "Старт программы..."
end

data, out = {}, ""

def CubatureSimpsonsF(a, b, c, d, e)
    i1, n = 0.0, 1 / e
	while true do
		i2 = i1
		hx = (b - a) / (2 * n)
		hy = (d - c) / (2 * n) 
        tmp = 0

		for i in 0..(n - 1) do
			for k in 0..(n - 1) do
				tmp = tmp + f(a + hx * (2 * i), c + hy * (2 * k)) + 4 * f(a + hx * (2 * i + 1), c + hy * (2 * k)) +
				    f(a + hx * (2 * i + 2), c + hy * (2 * k)) + 4 * f(a + hx * (2 * i), c + hy * (2 * k + 1)) +
				    16 * f(a + hx * (2 * i + 1), c + hy * (2 * k + 1)) + 4 * f(a + hx * (2 * i + 2), c + hy * (2 * k + 1)) +
				    f(a + hx * (2 * i), c + hy * (2 * k + 2)) + 4 * f(a + hx * (2 * i + 1), c + hy * (2 * k + 2)) +
				    f(a + hx * (2 * i + 2), c + hy * (2 * k + 2))
            end
        end
        i1 = (hx * hy / 9) * tmp
		n *= 2

		break if (i2 - i1).abs < 3 * e
    end
    return i1
end

p CubatureSimpsonsF(a, b, c, d, 1e-3)