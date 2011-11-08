	.file	"main.c"
# GNU C (Gentoo 4.6.2 p1.0, pie-0.4.5) version 4.6.2 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 4.6.2, GMP version 5.0.2, MPFR version 3.1.0, MPC version 0.9
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  main.c -D_FORTIFY_SOURCE=2 -mtune=generic -march=x86-64
# -auxbase-strip main.S -O2 -Wall -Wextra -fverbose-asm
# options enabled:  -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcaller-saves -fcombine-stack-adjustments -fcommon
# -fcompare-elim -fcprop-registers -fcrossjumping -fcse-follow-jumps
# -fdefer-pop -fdelete-null-pointer-checks -fdevirtualize -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -fexpensive-optimizations
# -fforward-propagate -ffunction-cse -fgcse -fgcse-lm
# -fguess-branch-probability -fident -fif-conversion -fif-conversion2
# -findirect-inlining -finline -finline-functions-called-once
# -finline-small-functions -fipa-cp -fipa-profile -fipa-pure-const
# -fipa-reference -fipa-sra -fira-share-save-slots -fira-share-spill-slots
# -fivopts -fkeep-static-consts -fleading-underscore -fmath-errno
# -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
# -fomit-frame-pointer -foptimize-register-move -foptimize-sibling-calls
# -fpartial-inlining -fpeephole -fpeephole2 -fprefetch-loop-arrays
# -freg-struct-return -fregmove -freorder-blocks -freorder-functions
# -frerun-cse-after-loop -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-insns2
# -fshow-column -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types
# -fstrict-aliasing -fstrict-overflow -fstrict-volatile-bitfields
# -fthread-jumps -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
# -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-copy-prop
# -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slp-vectorize
# -ftree-sra -ftree-switch-conversion -ftree-ter -ftree-vect-loop-version
# -ftree-vrp -funit-at-a-time -funwind-tables -fvect-cost-model
# -fverbose-asm -fzee -fzero-initialized-in-bss -m128bit-long-double -m64
# -m80387 -maccumulate-outgoing-args -malign-stringops -mfancy-math-387
# -mfp-ret-in-387 -mglibc -mieee-fp -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mtls-direct-seg-refs

# Compiler executable checksum: 4d5d86aeeca6239ac09ceb17df786fc1

	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%i"
.LC1:
	.string	"%s%*s"
.LC2:
	.string	"%s %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB58:
	.cfi_startproc
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$.LC0, %edi	#,
	xorl	%eax, %eax	#
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp	#,
	.cfi_def_cfa_offset 96
	leaq	24(%rsp), %rsi	#,
	call	__isoc99_scanf	#
	movl	$11000000, %edi	#,
	call	malloc	#
	movl	$8000000, %edi	#,
	movq	%rax, 8(%rsp)	#, %sfp
	call	malloc	#
	movl	$8000000, %edi	#,
	movq	%rax, %rbp	#, a
	call	malloc	#
	movl	$728, %edi	#,
	movq	%rax, %r12	#, b
	call	malloc	#
	movq	8(%rsp), %rdx	# %sfp, ivtmp.133
	movq	%rax, %rbx	#, count
	xorl	%eax, %eax	# ivtmp.136
	.p2align 4,,10
	.p2align 3
.L2:
	movq	%rdx, 0(%rbp,%rax)	# ivtmp.133, MEM[base: a_15, index: ivtmp.136_45, offset: 0B]
	addq	$8, %rax	#, ivtmp.136
	addq	$11, %rdx	#, ivtmp.133
	cmpq	$8000000, %rax	#, ivtmp.136
	jne	.L2	#,
	movl	24(%rsp), %eax	# z, z.3
	leal	-1(%rax), %edx	#, tmp275
	testl	%eax, %eax	# z.3
	movl	%edx, 24(%rsp)	# tmp275, z
	je	.L28	#,
.L17:
	leaq	28(%rsp), %rsi	#,
	movl	$.LC0, %edi	#,
	xorl	%eax, %eax	#
	call	__isoc99_scanf	#
	movl	28(%rsp), %eax	# n, n
	movq	8(%rsp), %rdi	# %sfp,
	xorl	%esi, %esi	#
	movl	$11000000, %ecx	#,
	leal	(%rax,%rax,4), %edx	#, tmp250
	leal	(%rax,%rdx,2), %eax	#, tmp252
	movslq	%eax, %rdx	# tmp252, tmp253
	call	__memset_chk	#
	movl	28(%rsp), %r15d	# n, n.0
	testl	%r15d, %r15d	# n.0
	jle	.L4	#,
	movq	%rbp, %r14	# a, ivtmp.125
	xorl	%r13d, %r13d	# i
	.p2align 4,,10
	.p2align 3
.L5:
	movq	(%r14), %rsi	# MEM[base: D.5077_91, offset: 0B],
	xorl	%eax, %eax	#
	movl	$.LC1, %edi	#,
	addl	$1, %r13d	#, i
	addq	$8, %r14	#, ivtmp.125
	call	__isoc99_scanf	#
	movl	28(%rsp), %r15d	# n, n.0
	cmpl	%r13d, %r15d	# i, n.0
	jg	.L5	#,
.L4:
	leal	-1(%r15), %r9d	#, pretmp.59
	movl	$9, %edx	#, ivtmp.120
	xorl	%eax, %eax	# tmp281
	movl	$91, %r8d	#, tmp282
	mov	%r9d, %ecx	# pretmp.59, tmp285
	movslq	%r9d, %r10	# pretmp.59, pretmp.59
	negq	%rcx	# tmp285
	salq	$3, %r10	#, tmp289
	leaq	-8(,%rcx,8), %rsi	#, D.5048
	.p2align 4,,10
	.p2align 3
.L11:
	movq	%rbx, %rdi	# count, count
	movq	%r8, %rcx	# tmp282, tmp256
	testl	%r15d, %r15d	# n.0
	rep stosq
	jle	.L6	#,
	.p2align 4,,10
	.p2align 3
.L7:
	movq	0(%rbp,%rcx,8), %rdi	# MEM[base: a_198, index: ivtmp.110_194, step: 8, offset: 0B], MEM[base: a_198, index: ivtmp.110_194, step: 8, offset: 0B]
	addq	$1, %rcx	#, ivtmp.110
	movsbq	(%rdi,%rdx), %rdi	# *D.4856_49, *D.4856_49
	addq	$1, (%rbx,%rdi,8)	#, *D.4860_53
	cmpl	%ecx, %r15d	# ivtmp.110, n.0
	jg	.L7	#,
.L6:
	xorl	%ecx, %ecx	# ivtmp.107
	.p2align 4,,10
	.p2align 3
.L8:
	movq	(%rbx,%rcx), %rdi	# MEM[base: count_17, index: ivtmp.107_101, offset: 0B], MEM[base: count_17, index: ivtmp.107_101, offset: 0B]
	addq	%rdi, 8(%rbx,%rcx)	# MEM[base: count_17, index: ivtmp.107_101, offset: 0B], MEM[base: count_17, index: ivtmp.107_101, offset: 8B]
	addq	$8, %rcx	#, ivtmp.107
	cmpq	$720, %rcx	#, ivtmp.107
	jne	.L8	#,
	testl	%r9d, %r9d	# pretmp.59
	js	.L9	#,
	leaq	0(%rbp,%r10), %r14	#, D.5039
	xorw	%cx, %cx	#
	.p2align 4,,10
	.p2align 3
.L10:
	movq	(%r14,%rcx), %r11	# MEM[base: D.5039_107, index: ivtmp.97_105, offset: 0B], MEM[base: D.5039_107, index: ivtmp.97_105, offset: 0B]
	subq	$8, %rcx	#, ivtmp.97
	movsbq	(%r11,%rdx), %rdi	# *D.4856_79, *D.4856_79
	leaq	(%rbx,%rdi,8), %r13	#, D.4860
	movq	0(%r13), %rdi	# *D.4860_83, *D.4860_83
	subq	$1, %rdi	#, D.4870
	cmpq	%rsi, %rcx	# D.5048, ivtmp.97
	movq	%rdi, 0(%r13)	# D.4870, *D.4860_83
	movq	%r11, (%r12,%rdi,8)	# MEM[base: D.5039_107, index: ivtmp.97_105, offset: 0B], *D.4872_88
	jne	.L10	#,
.L9:
	subq	$1, %rdx	#, ivtmp.120
	cmpq	$-1, %rdx	#, ivtmp.120
	je	.L29	#,
	movq	%rbp, %rcx	# a, a
	movq	%r12, %rbp	# b, a
	movq	%rcx, %r12	# a, b
	jmp	.L11	#
.L29:
	testl	%r15d, %r15d	# n.0
	jg	.L30	#,
.L12:
	movq	%r12, %rax	# b, a
	movq	%rbp, %r12	# a, b
	movq	%rax, %rbp	# a, a
	movl	24(%rsp), %eax	# z, z.3
	leal	-1(%rax), %edx	#, tmp275
	testl	%eax, %eax	# z.3
	movl	%edx, 24(%rsp)	# tmp275, z
	jne	.L17	#,
.L28:
	movq	8(%rsp), %rdi	# %sfp,
	call	free	#
	movq	%rbp, %rdi	# a,
	call	free	#
	movq	%r12, %rdi	# b,
	call	free	#
	movq	%rbx, %rdi	# count,
	call	free	#
	addq	$40, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax	#
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret
.L30:
	.cfi_restore_state
	movq	%r12, %r13	# b, ivtmp.83
	xorl	%r14d, %r14d	# i
	movl	%r15d, %edx	# n.0, n.0
.L16:
	leal	-1(%rdx), %eax	#, tmp272
	movq	0(%r13), %r15	#* ivtmp.83, prephitmp.71
	cmpl	%r14d, %eax	# i, tmp272
	jle	.L14	#,
	movq	8(%r13), %rsi	# MEM[base: D.5022_201, offset: 8B], MEM[base: D.5022_201, offset: 8B]
	movq	%r15, %rdi	# prephitmp.71,
	movl	%edx, (%rsp)	#,
	call	strcmp	#
	testl	%eax, %eax	# D.3399
	movl	(%rsp), %edx	#,
	jne	.L14	#,
	addl	$1, count.3390(%rip)	#, count
.L15:
	addl	$1, %r14d	#, i
	addq	$8, %r13	#, ivtmp.83
	cmpl	%r14d, %edx	# i, n.0
	jle	.L12	#,
	jmp	.L16	#
	.p2align 4,,10
	.p2align 3
.L14:
	movl	count.3390(%rip), %ecx	# count,
	movq	%r15, %rdx	# prephitmp.71,
	movl	$.LC2, %esi	#,
	movl	$1, %edi	#,
	xorl	%eax, %eax	#
	call	__printf_chk	#
	movl	$1, count.3390(%rip)	#, count
	movl	28(%rsp), %edx	# n, n.0
	jmp	.L15	#
	.cfi_endproc
.LFE58:
	.size	main, .-main
	.data
	.align 4
	.type	count.3390, @object
	.size	count.3390, 4
count.3390:
	.long	1
	.ident	"GCC: (Gentoo 4.6.2 p1.0, pie-0.4.5) 4.6.2"
	.section	.note.GNU-stack,"",@progbits
