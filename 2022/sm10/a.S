// float func(float a, float b, float c, float z = 0);

func:
  push %ebp
  movl %esp, %ebp

  // 0(%ebp) -> old_ebp
  // 4(%ebp) -> ret_addr

  movups  8(%ebp), %xmm0

  // movss 8(%ebp), %xmm0
  // movss 12(%ebp), %xmm1
  // movss 16(%ebp), %xmm2

  mulps %xmm0, %xmm0

  // mulss %xmm0, %xmm0
  // mulss %xmm1, %xmm1
  // mulss %xmm2, %xmm2

  haddps %xmm0, %xmm0
  haddps %xmm0, %xmm0

  // addss %xmm0, %xmm1
  // addss %xmm2, %xmm1

  sqrtss %xmm0, %xmm0

  movss %xmm0, -4(%esp)

  flds -4(%esp)

  leave