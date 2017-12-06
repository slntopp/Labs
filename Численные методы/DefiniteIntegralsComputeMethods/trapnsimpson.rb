# Для тестов используется функция: 1 / (exp(x) + exp(-x)), при пределах [0, 1.0]
# При ручном подсчете результат: 0.4328847866
# ruby trapnsimpson.rb "1 / (exp(x) + exp(-1 * x))" 0 1 0.4328847866
require 'progress_bar'

$func, a, b, manual = ARGV
a, b, manual = a.to_f, b.to_f, manual.to_f
File.open('math.rb', 'w') { |file| file.write("def exp(t) return Math.exp(t) end \ndef f(x, y = 0) return #{$func} end") }
require './math.rb'
require './funcs.rb'

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
for i in 2..6 do
    for j in [1.0, 2.0, 4.0, 6.0, 8.0]
        data["#{j}e-#{i}"] = {}
        puts "Формула Трапеций(точность E = #{j}e-#{i}):"
        puts "\t\tРезультат:\t#{data["#{j}e-#{i}"][:trap] = Trapese(a, b, "#{j}e-#{i}".to_f).to_f}"
        puts "Формула Трапеций правильная(точность E = #{j}e-#{i}):"
        puts "\t\tРезультат:\t#{data["#{j}e-#{i}"][:trapcorrect] = TrapeseRight(a, b,"#{j}e-#{i}".to_f).to_f}"
        puts "Формула Симпсона(точность E = #{j}e-#{i}):"
        puts "\t\tРезультат:\t#{data["#{j}e-#{i}"][:simp] = SimpsonsF(a, b, "#{j}e-#{i}".to_f).to_f}"
        puts "Формула Симпсона правильная(точность E = #{j}e-#{i}):"
        puts "\t\tРезультат:\t#{data["#{j}e-#{i}"][:simpcorrect] = SimpsonsFRight(a, b, "#{j}e-#{i}".to_f).to_f}"
    end
end

data.each { |e, values|
    out += "\t[\"#{e}\", #{manual}, #{values[:trap]}, #{values[:trapcorrect]}, #{values[:simp]}, #{values[:simpcorrect]}],\n"
}
template = File.read('template.html').split(/\n/)
template[template.index('              ###')] = out

# out = ""
# data.each { |e, values|
#     out += "\t[\"#{e}\", 0, #{values[:trap] - manual}, #{values[:trapcorrect] - manual}, #{values[:simp] - manual}, #{values[:simpcorrect] - manual}],\n"
# }
# template = File.read('template.html').split(/\n/)
# template[template.index('        %%%')] = out
File.open('out.html', 'w') { |file| file.write(template.join("\n")) }