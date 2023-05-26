    .name "Darius"
	.comment "LOL champion"


	sti r1, %:hi, %1
hi:	live %123
	ld %0, r3
    fork %:surprise
	zjmp %:hi

suprise:
    ld %0, r1
    sti r3, r1, r2
    zjmp %:hi

