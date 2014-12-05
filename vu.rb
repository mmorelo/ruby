class VU
    include Comparable
    def initialize(volume)
        @vol=volume
    end
    def inspect
        '#' * @vol
    end
    def <=>(other)
        self.vol <=> other.vol
    end
    def scc
        raise( IndexError, "Volume too big") if @vol >= 9
        VU.new(@vol.succ)
    end
end

medium_volume = VU.new(4)..VU.new(7)
medium_volume.to_a 
medium_volume.include?(VU.new(3))