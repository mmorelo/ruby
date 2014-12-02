class Song 
    attr_reader :name, :artist, :duration 
    attr_writer :name, :artist, :duration 
    @@plays = 0

    def initialize(name, artist, duration)
        @name     = name
        @artist   = artist
        @duration = duration     
        @plays    = 0
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


class SongList
    def initialize
        @songs = Array.new
        @index = WordIndex.new
    end
    def append(song)
        @songs.push( song )
        @index.add_to_index( song, song.name, song.artist )
        self
    end
    def