# Get the file as a command line argument
ARGV.each do |a|
# open file and parse lines
File.open(a).each do |line|
	#split the lines with two delimiters, / and :
	path = line.split(/[\/,:]/)
	# select the files with cpp extension.
	path = path.select{|e| e =~ /\.cpp$/}
	puts path
end
end

