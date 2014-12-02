class Song 
	attr_reader :name, :artist, :duration 
	attr_writer :name, :artist, :duration 
	@@plays = 0

	def initialize(name, artist, duration)
		@name 	  = name
		@artist	  = artist
		@duration = duration	 
		@plays 	  = 0
	end
	def to_s
		"Song: #{@name} #{@artist} #{@duration} "
	end

	def play
		@@plays += 1
		@plays +=1
		"This song has been played #{@plays} times, total songs #{@@plays}"
	end
end


class KaraokeSong < Song
	def initialize ( name, artist, duration, lyrics )
		super( name, artist, duration )
		@lyrics = lyrics
		
		end
	def to_s
		super + " #{@lyrics}"
	end

end


class MyLogger
	private_class_method :new
	@@logger = nil
	def MyLogger.create
		@@logger = new unless @@logger
		@@logger
	end
end

#pag 74

def three_times
 yield
 yield
 yield
 end
three_times { puts "Hello" }

def fib_up_to(max)
i1, i2 = 1, 1 # parallel assignment (i1 = 1 and i2 = 1)
while i1 <= max
yield i1
i1, i2 = i2, i1+i2
end
end
fib_up_to(1000) {|f| print f, " " }


def fib_up_to(max)
i1, i2 = 1, 1 # parallel assignment (i1 = 1 and i2 = 1)
while i1 <= max
yield i1
i1, i2 = i2, i1+i2
end
end
fib_up_to(1000) {|f| print f, " " }


class File
    def File.open_and_process(*args)
        f = File.open(*args)
        yield f
    f.close()
    end
end

File.open_and_process("testfile", "r") do |file|
    while line = file.gets
    puts line
    end
end

def n_times(thing)
    return lambda {|n| thing * n }
end

p1 = n_times(23)
p1.call(3) 


string = <<END_OF_STRING
The body of the string
is the input lines up to
one ending with the same
text that followed the '<<'
END_OF_STRING

#pag 89

class WordIndex
    def initialize
        @index = {}
    end
    def add_to_index( obj, *phrases)
        phrases.each  do |phrase|
            phrase.scan( /\w[-\w']+/) do |word|
                word.downcase!
                @index[word] = [] if @index[word].nil?
                @index[word].push(obj)
            end
        end
    end
    def lookup(word)
        @index[word.downcase]
    end
end

