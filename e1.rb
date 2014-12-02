#!/user/bin/env ruby

class MuchosSaludos
	
	attr_accessor :names

	def initialize ( names = World )
		@names = names
	end
	def say_hi()
		if @names.nil?
			puts "..."
		elsif @names.respond_to?("each")
			@names.each do |name| 
				puts "Hi #{name}!"
		else
			puts "Hi #{@name}"
		end

	end
	def say_bye()
		if @names.respond_to?("join")
			puts "Bye #{@names.join(", ")}. Come back!"
		else
			puts "Bye #{@names}"
		end
	end


end #class

