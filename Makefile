mu:
	gcc mu.c -o mu
	gcc mu1_opt.c -o mu1_opt 
	gcc mu2_opt.c -o mu2_opt 
	gcc mu3_opt.c -o mu3_opt 
	gcc mu4_opt.c -o mu4_opt 
clean: 
	rm mu
	rm mu1_opt
	rm mu2_opt
	rm mu3_opt
	rm mu4_opt
