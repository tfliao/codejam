
$cars = Array.new
$hash = Hash.new
$graph = Hash.new

def check(car)
	from, to = car[0], car[-1]
	h = car.index(/[^#{from.chr}]/)
	
	# must all the same if begin, end are same letter
	return h == NIL if from == to
	
	last = car[h]
	sp = h
	(h+1).upto(car.length-1) do |i|
		if car[i] != last then
			return false if i-sp != $hash[last] 
			last, sp = car[i], i
		end
	end
	
	true
end

def check_graph()
	$graph.each do |k, v|
		n = v[:out]
		while n != NIL do
			return false if n == k # loop
			n = $graph[n][:out]
		end
	end
	true
end

def make_graph()
	$graph = Hash.new
	$hash.each_key do |k|
		$graph[k] = { :in => NIL, :out => NIL, :loop => 0 }
	end
	
	$cars.each do |car|
		return false if !check(car) 
		
		from, to = car[0], car[-1]
		if from == to then
			$graph[from][:loop] += 1
			next
		end
		
		# from, to multiple loc
		return false if $graph[from][:out] != NIL || $graph[to][:in] != NIL 
		
		$graph[from][:out] = to
		$graph[to][:in] = from
	end
	return check_graph()
end

def mod(x) 
	x.divmod(1000000007)[1]
end

def factor(x)
	ans = 1
	1.upto(x) { |v| ans = mod(ans*v) }
	ans
end

def solv_sub(n)
	ans = 1
	until n == NIL do
		node = $graph[n] 
		ans = mod(ans*factor(node[:loop]))
		n = node[:out]
	end
	ans
end

def solv()
	return 0 if !make_graph()
	
	ans, cnt = 1, 0
	$graph.each do |k, v|
		if v[:in] == NIL && (v[:loop] != 0 || v[:out] != NIL) then
			sub = solv_sub(k)
			ans = mod(ans*sub)
			cnt += 1
		end
	end
	return mod(ans*factor(cnt))
end

gets.to_i.times do |nCase|
	$cars = Array.new
	$hash = Hash.new
	
	gets # skip line with number of car
	line = gets
	line.each_byte do |c| 
		next if c < 97 || c > 122
		$hash[c] = 0 if $hash[c] == NIL
		$hash[c] += 1
	end
	
	$cars = line.split
	puts "Case ##{nCase+1}: #{solv()}"
end
