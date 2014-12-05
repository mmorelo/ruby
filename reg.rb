def show_match( text, reg )
    if text =~ reg
        "#{$`}<<#{$&}>>#{$'}"
    else
        "no match"
    end
end


def mixed_case(name)
    name.gsub(/\b\w/) {|first| first.upcase }
end