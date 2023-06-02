.global reverse_in_place

reverse_in_place:
	#rdi = str
	#rsi = end
	#rdx = count 
	#rcx = temp
	#r10 = holder
	#r11 = holder2
	
	xor %rdx, %rdx #count = 0
	test %rdi, %rdi #if !str, return NULL
	jz return_null

loop1:
	mov (%rsi), %r10 #holder = *end
	test (%rsi), %r10 #if *end = 0, end loop
	jz loop1_done
	inc %rsi #end++
	inc %rdx #count++
	jmp loop1

loop1_done:
	dec %rsi #end--
	dec %rdx #count--
	jmp loop2

loop2:
	cmp %rdi, %rsi #while str < end
	jle loop2_done
	mov (%rdi), %rcx #temp = *str
	mov (%rsi), %r11 #holder2 = *end
	mov %r11, (%rdi) #*str = holder2
	inc %rdi #*str++
	mov %rcx, (%rsi) #*end = temp
	dec %rsi #*end--
	jmp loop2	

loop2_done:
	mov %rdx, %rax #return count
	jmp done

return_null:
	xor %rax, %rax #return NULL
	jmp done
done:
	ret
