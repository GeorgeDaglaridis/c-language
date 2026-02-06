# Repeatedly add the exact same number to itself for 5 time in a row
# OR
# Perform the addition of x1 to itself in a loop for 5 times

_start:
    # ABI equivalent: li ra, 2
    addi x1, x0, 2
    # ABI equivalent: li sp, 5
    addi x2, x0, 5
    # ABI equivalent: li gp, 5
    addi x3, x0, 0

repeat_addition:
    # ABI equivalent: add gp,gp,ra
    add x3, x3, x1
    # ABI equivalent: addi sp,sp,-1 
    addi x2, x2, -1 

    # Branch offset (repeat_addition) basically matches with the instruction right below it. So the branch offset basically holds the address where instruction in line 11 is stored. 
    # ABI equivalent: sp, the address containing the instruction in line 11. 
    # branch not equal (if x2!=0) then jump to offset
    bne x2, x0, repeat_addition  

    j . #jump again here















# First program explained in videos
#_start:
#    j _start
