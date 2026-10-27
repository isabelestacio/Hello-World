.data
    helloworld: .string "Hello World! \n"

.text
    .global main

main:
    push $helloworld
    call printf
    add $4, %esp
    ret
