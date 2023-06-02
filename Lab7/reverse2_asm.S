.global reverse_list_asm

reverse_list_asm:
	#Write the code for lines 19-24, 26-27 below
	#rdi <- head
	#rax <- reversed head

	#rsi <- curr
	#rdx <- prev
	
	test %rdi, %rdi #if (head == NULL) return NULL; 
	jz ret_null
	mov %rdi, %rsi # curr = head;
	xor %rdx, %rdx # prev = NULL; 

while_begin: 
	mov 8(%rdi), %rcx # rcx = head->next
	test %rcx, %rcx # if(head->next == NULL) break out of loop;
	jz while_done
	mov 8(%rdi), %rdi # head = head->next;
	mov %rdx, 8(%rsi) # curr->next = prev;
	mov %rsi, %rdx # prev = curr;
	mov %rdi, %rsi #curr = head;
	jmp while_begin	#jump to while_begin
while_done:
	mov %rdx, 8(%rsi) # curr->next = prev;
	mov %rsi, %rax  #return curr;
	jmp done
ret_null: 
	xor %rax, %rax # return NULL; 
done:
	ret
