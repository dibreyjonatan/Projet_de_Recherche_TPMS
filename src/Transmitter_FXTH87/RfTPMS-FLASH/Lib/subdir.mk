################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/Users/admin/workspace/11.RfTPMS/Lib/FXTH870000.c" \

C_SRCS += \
C:/Users/admin/workspace/11.RfTPMS/Lib/FXTH870000.c \

OBJS += \
./Lib/FXTH870000_c.obj \

OBJS_QUOTED += \
"./Lib/FXTH870000_c.obj" \

C_DEPS += \
./Lib/FXTH870000_c.d \

C_DEPS_QUOTED += \
"./Lib/FXTH870000_c.d" \

OBJS_OS_FORMAT += \
./Lib/FXTH870000_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Lib/FXTH870000_c.obj: $(ProjDirPath)/Lib/FXTH870000.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/FXTH870000.args" -ObjN="Lib/FXTH870000_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/FXTH870000_c.d: $(ProjDirPath)/Lib/FXTH870000.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


