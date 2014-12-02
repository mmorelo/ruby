ARGV.each do |a|
File.open(a).each do |line|
	if line.include?"+"
	print " #{line}"	
	end
end
end