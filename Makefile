mu:
	gcc mu.c -o mu -std=c99
	gcc mu1_opt.c -o mu1_opt -std=c99
	gcc mu2_opt.c -o mu2_opt -std=c99
	gcc mu3_opt.c -o mu3_opt -std=c99
	gcc mu4_opt.c -o mu4_opt -std=c99
clean: 
	rm mu
	rm mu1_opt
	rm mu2_opt
	rm mu3_opt
	rm mu4_opt
