message("FOO_A in sub >> ${FOO_A}")
set(FOO_A "FOO_A child")
message("FOO_A in sub >> ${FOO_A}")

message("FOO_B in sub >> ${FOO_B}")
set(FOO_B "FOO_B child" PARENT_SCOPE)
message("FOO_B in sub >> ${FOO_B}")

