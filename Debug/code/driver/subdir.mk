################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../code/driver/encoder.c" \
"../code/driver/menu.c" \
"../code/driver/pid.c" 

COMPILED_SRCS += \
"code/driver/encoder.src" \
"code/driver/menu.src" \
"code/driver/pid.src" 

C_DEPS += \
"./code/driver/encoder.d" \
"./code/driver/menu.d" \
"./code/driver/pid.d" 

OBJS += \
"code/driver/encoder.o" \
"code/driver/menu.o" \
"code/driver/pid.o" 


# Each subdirectory must supply rules for building sources it contributes
"code/driver/encoder.src":"../code/driver/encoder.c" "code/driver/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Infineon/workspace/mouz1/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/driver/encoder.o":"code/driver/encoder.src" "code/driver/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/driver/menu.src":"../code/driver/menu.c" "code/driver/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Infineon/workspace/mouz1/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/driver/menu.o":"code/driver/menu.src" "code/driver/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/driver/pid.src":"../code/driver/pid.c" "code/driver/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Infineon/workspace/mouz1/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/driver/pid.o":"code/driver/pid.src" "code/driver/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-code-2f-driver

clean-code-2f-driver:
	-$(RM) ./code/driver/encoder.d ./code/driver/encoder.o ./code/driver/encoder.src ./code/driver/menu.d ./code/driver/menu.o ./code/driver/menu.src ./code/driver/pid.d ./code/driver/pid.o ./code/driver/pid.src

.PHONY: clean-code-2f-driver

