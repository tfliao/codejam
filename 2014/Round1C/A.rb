def gcd(p, q)
	until p.divmod(q)[1] == 0 do
		p, q = q, p.divmod(q)[1]
	end
	q
end

def check(q)
	1.upto(40) do |i|
		if (q & (1<<i)) != 0 then
			return q == (1<<i)
		end
	end
	false
end

def solv_core(p, q)
	cnt = 0
	until (p & q) != 0 do
		cnt += 1
		q /= 2		
	end
	cnt
end

def solv(p, q)
	g = gcd(p, q)
	p, q = p/g, q/g
	return "impossible" if !check(q)
	ans = solv_core(p,q)
	return "impossible" if ans > 40
	return ans
end

gets.to_i.times do |nCase|
  p, q = gets.split('/').map(&:to_i)
  puts "Case ##{nCase+1}: #{solv(p, q)}"
end
