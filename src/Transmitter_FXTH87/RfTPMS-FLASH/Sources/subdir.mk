################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/Users/admin/workspace/11.RfTPMS/Sources/Interrupts.c" \
"C:/Users/admin/workspace/11.RfTPMS/Sources/delay.c" \
"C:/Users/admin/workspace/11.RfTPMS/Sources/fxth87.c" \
"C:/Users/admin/workspace/11.RfTPMS/Sources/main.c" \
"C:/Users/admin/workspace/11.RfTPMS/Sources/printf.c" \
"C:/Users/admin/workspace/11.RfTPMS/Sources/rf.c" \

C_SRCS += \
C:/Users/admin/workspace/11.RfTPMS/Sources/Interrupts.c \
C:/Users/admin/workspace/11.RfTPMS/Sources/delay.c \
C:/Users/admin/workspace/11.RfTPMS/Sources/fxth87.c \
C:/Users/admin/workspace/11.RfTPMS/Sources/main.c \
C:/Users/admin/workspace/11.RfTPMS/Sources/printf.c \
C:/Users/admin/workspace/11.RfTPMS/Sources/rf.c \

OBJS += \
./Sources/Interrupts_c.obj \
./Sources/delay_c.obj \
./Sources/fxth87_c.obj \
./Sources/main_c.obj \
./Sources/printf_c.obj \
./Sources/rf_c.obj \

OBJS_QUOTED += \
"./Sources/Interrupts_c.obj" \
"./Sources/delay_c.obj" \
"./Sources/fxth87_c.obj" \
"./Sources/main_c.obj" \
"./Sources/printf_c.obj" \
"./Sources/rf_c.obj" \

C_DEPS += \
./Sources/Interrupts_c.d \
./Sources/delay_c.d \
./Sources/fxth87_c.d \
./Sources/main_c.d \
./Sources/printf_c.d \
./Sources/rf_c.d \

C_DEPS_QUOTED += \
"./Sources/Interrupts_c.d" \
"./Sources/delay_c.d" \
"./Sources/fxth87_c.d" \
"./Sources/main_c.d" \
"./Sources/printf_c.d" \
"./Sources/rf_c.d" \

OBJS_OS_FORMAT += \
./Sources/Interrupts_c.obj \
./Sources/delay_c.obj \
./Sources/fxth87_c.obj \
./Sources/main_c.obj \
./Sources/printf_c.obj \
./Sources/rf_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Interrupts_c.obj: $(SOURCES)/Interrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Interrupts.args" -ObjN="Sources/Interrupts_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Interrupts_c.d: $(SOURCES)/Interrupts.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/delay_c.obj: $(ProjDirPath)/Sources/delay.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/delay.args" -ObjN="Sources/delay_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/delay_c.d: $(ProjDirPath)/Sources/delay.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/fxth87_c.obj: $(ProjDirPath)/Sources/fxth87.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/fxth87.args" -ObjN="Sources/fxth87_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/fxth87_c.d: $(ProjDirPath)/Sources/fxth87.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: $(ProjDirPath)/Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.d: $(ProjDirPath)/Sources/main.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/printf_c.obj: $(ProjDirPath)/Sources/printf.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/printf.args" -ObjN="Sources/printf_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/printf_c.d: $(ProjDirPath)/Sources/printf.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/rf_c.obj: $(ProjDirPath)/Sources/rf.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/rf.args" -ObjN="Sources/rf_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/rf_c.d: $(ProjDirPath)/Sources/rf.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


