################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../code/common/AHRS.c" \
"../code/common/algorithm.c" 

COMPILED_SRCS += \
"code/common/AHRS.src" \
"code/common/algorithm.src" 

C_DEPS += \
"./code/common/AHRS.d" \
"./code/common/algorithm.d" 

OBJS += \
"code/common/AHRS.o" \
"code/common/algorithm.o" 


# Each subdirectory must supply rules for building sources it contributes
"code/common/AHRS.src":"../code/common/AHRS.c" "code/common/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Infineon/workspace/mouz1/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/common/AHRS.o":"code/common/AHRS.src" "code/common/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/common/algorithm.src":"../code/common/algorithm.c" "code/common/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Infineon/workspace/mouz1/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/common/algorithm.o":"code/common/algorithm.src" "code/common/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-code-2f-common

clean-code-2f-common:
	-$(RM) ./code/common/AHRS.d ./code/common/AHRS.o ./code/common/AHRS.src ./code/common/algorithm.d ./code/common/algorithm.o ./code/common/algorithm.src

.PHONY: clean-code-2f-common

