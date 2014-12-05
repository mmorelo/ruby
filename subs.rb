


text = File.read(ARGV[0])
new_text = text.gsub(/\!/, '-->') 
File.open(ARGV[0], "w") {|file| file.puts new_text }



