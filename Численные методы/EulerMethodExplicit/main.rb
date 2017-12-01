require './funcs.rb'

puts "Явный метод Эйлера:"
u, dots = EulerExplicit([1, 1, 1], 1, 2, true, true)

template = File.read('template.html').split(/\n/)

out = ""
dots.each do | pair |
  out += "          [#{pair[:t].to_s}, #{pair[:u].to_s}],\n"
end
template[template.index('###')] = out

u = EulerImplicit([1, 1, 1], 1, 2, true, true)

dots = File.read('nme.txt').split(/\n/)
out  = ""
dots.each do |pair|
  out += "          [#{(pair.split(' ')[0]).to_s}, NaN, #{((pair.split(' ')[1]) * 1.01).to_s}],\n"
end
template[template.index('%%%')] = out
template[template.index('%%%')] = "['0', 1],\n['1', 2]\n"
File.open('out.html', 'w') { |file| file.write(template.join("\n")) }
