cmake_minimum_required(VERSION 3.18.0)

project(parseArguments)

function(STUDENT_PRINTER)
    cmake_parse_arguments(STUDENT 
        "MALE" 
        "FULLNAME;AGE" 
        "SCORE" 
        ${ARGN} 
    )

    message("MALE = ${STUDENT_MALE}")
    message("FULLNAME = ${STUDENT_FULLNAME}")
    message("AGE = ${STUDENT_AGE}")
    message("SCORE = ${STUDENT_SCORE}")
endfunction()

STUDENT_PRINTER(MALE 
    FULLNAME 
        chuchucha 
    AGE 
        20 
    SCORE 
        100 
        200 
        300 
        400 
        500
)