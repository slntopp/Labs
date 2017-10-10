$stdout = File.open("in.txt", "w")

$cities = []
$cities = File.readlines("cities.dat")

for i in 1..1000
    puts( $cities[rand(153)] + (1000 - i + rand(100)).to_s + "\n" + rand(24).to_s + ":" + rand(60).to_s)
end