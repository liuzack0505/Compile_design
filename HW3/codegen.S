.global codegen
codegen:
  // BEGIN EPILOGUE
  sw s0, -4(sp) // save frame pointer
  addi sp, sp, -4
  addi s0, sp, 0 // set new frame pointer
  sw sp, -4(s0)
  sw s1, -8(s0)
  sw s2, -12(s0)
  sw s3, -16(s0)
  sw s4, -20(s0)
  sw s5, -24(s0)
  sw s6, -28(s0)
  sw s7, -32(s0)
  sw s8, -36(s0)
  sw s9, -40(s0)
  sw s10, -44(s0)
  sw s11, -48(s0)
  addi sp, s0, -96 // update stack pointer
  addi s0, s0, -96 // update s0
  // END EPILOGUE
  
  // declare id a and create its space in stack
  addi sp, sp, -8
  // push 4 into stack
  li t0, 4
  sw t0, -8(sp)
  addi sp, sp, -8
  // store in a space in stack
  lw t0, 0(sp)
  sw t0, -8(s0)
  addi sp, sp, 8
  // declare id b and create its space in stack
  addi sp, sp, -8
  // push value a into stack
  li t0, 1
  sw t0, -4(sp)
  lw t0, -8(s0)
  sw t0, -8(sp)
  addi sp, sp, -8
  // push 2 into stack
  li t0, 2
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop first two to sub
  lw t0, 0(sp)
  addi sp, sp, 8
  lw t1, 0(sp)
  addi sp, sp, 8
  sub t0, t1, t0
  sw t0, -8(sp)
  addi sp, sp, -8
  // push value a into stack
  li t0, 1
  sw t0, -4(sp)
  lw t0, -8(s0)
  sw t0, -8(sp)
  addi sp, sp, -8
  // push 1 into stack
  li t0, 1
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop first two to sub
  lw t0, 0(sp)
  addi sp, sp, 8
  lw t1, 0(sp)
  addi sp, sp, 8
  sub t0, t1, t0
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop first two to mul
  lw t0, 0(sp)
  addi sp, sp, 8
  lw t1, 0(sp)
  addi sp, sp, 8
  mul t0, t0, t1
  sw t0, -8(sp)
  addi sp, sp, -8
  // store in b space in stack
  lw t0, 0(sp)
  sw t0, -16(s0)
  addi sp, sp, 8
  // push 27 into stack
  li t0, 27
  sw t0, -8(sp)
  addi sp, sp, -8
  // push 1 into stack
  li t0, 1
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop two to execute the function digitalwrite
  lw a1, 0(sp)
  addi sp, sp, 8
  lw a0, 0(sp)
  addi sp, sp, 8
  // store the ra and jump to digitalWrite
  sw ra, -8(sp)
  addi sp, sp, -8
  jal ra, digitalWrite
  lw ra, 0(sp)
  addi sp, sp, 8
  
  // push value a into stack
  li t0, 1
  sw t0, -4(sp)
  lw t0, -8(s0)
  sw t0, -8(sp)
  addi sp, sp, -8
  // push 1000 into stack
  li t0, 1000
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop first two to mul
  lw t0, 0(sp)
  addi sp, sp, 8
  lw t1, 0(sp)
  addi sp, sp, 8
  mul t0, t0, t1
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop one to execute the function delay
  lw a0, 0(sp)
  addi sp, sp, 8
  // store the ra and jump to delay
  sw ra, -8(sp)
  addi sp, sp, -8
  jal ra, delay
  lw ra, 0(sp)
  addi sp, sp, 8
  
  // push 27 into stack
  li t0, 27
  sw t0, -8(sp)
  addi sp, sp, -8
  // push 1 into stack
  li t0, 1
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop two to execute the function digitalwrite
  lw a1, 0(sp)
  addi sp, sp, 8
  lw a0, 0(sp)
  addi sp, sp, 8
  // store the ra and jump to digitalWrite
  sw ra, -8(sp)
  addi sp, sp, -8
  jal ra, digitalWrite
  lw ra, 0(sp)
  addi sp, sp, 8
  
  // push value b into stack
  li t0, 2
  sw t0, -4(sp)
  lw t0, -16(s0)
  sw t0, -8(sp)
  addi sp, sp, -8
  // push 1000 into stack
  li t0, 1000
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop first two to mul
  lw t0, 0(sp)
  addi sp, sp, 8
  lw t1, 0(sp)
  addi sp, sp, 8
  mul t0, t0, t1
  sw t0, -8(sp)
  addi sp, sp, -8
  // pop one to execute the function delay
  lw a0, 0(sp)
  addi sp, sp, 8
  // store the ra and jump to delay
  sw ra, -8(sp)
  addi sp, sp, -8
  jal ra, delay
  lw ra, 0(sp)
  addi sp, sp, 8
  
  
  // BEGIN EPILOGUE
  addi s0, s0, 96 // update s0
  lw s11, -48(s0)
  lw s10, -44(s0)
  lw s9, -40(s0)
  lw s8, -36(s0)
  lw s7, -32(s0)
  lw s6, -28(s0)
  lw s5, -24(s0)
  lw s4, -20(s0)
  lw s3, -16(s0)
  lw s2, -12(s0)
  lw s1, -8(s0)
  lw sp, -4(s0)
  addi sp, sp, 4
  lw s0, -4(sp)
  // END EPILOGUE
  
  jalr zero, 0(ra) // return
