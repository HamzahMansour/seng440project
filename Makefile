mu:
	gcc mu.c -o mu
	gcc mu1_opt.c -o mu1_opt
	gcc mu2_opt.c -o mu2_opt
clean: 
	rm mu
	rm mu1_opt
	rm mu2_opt
