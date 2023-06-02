.global add_arrays

add_arrays:
	#rdi = arr1
	#rsi = arr2
	#rdx = num
	#rcx = result
	#r8 = sum
	#r9 = i
	#r10 = temp
	#r11 = temp2
	
	xor %r8, %r8 #sum = 0
	xor %r9, %r9 #i = 0

while_start:
	cmp %r9, %rdx #if i >= num, end loop
	jle while_done
	mov (%rdi, %r9, 8), %r10 #temp = arr1[i]
	mov (%rsi, %r9, 8), %r11 #temp2 = arr2[i]
	add %r11, %r10 #arr1[i] = arr1[i] + arr2[i]
	mov %r10, (%rcx, %r9, 8) #result[i] = arr1[i]
	add (%rcx, %r9, 8), %r8 #sum = sum + result[i]
	inc %r9 #i++
	jmp while_start

while_done:
	mov %r8, %rax #return sum
	jmp done
done:
	ret

