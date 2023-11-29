#---------------------------- Path defs -------------------------------------
DPU_BIN_DIR := ./build/bin/dpu
CPU_BIN_DIR := ./build/bin/cpu

#---------------------------- Working Directories ----------------------------
src_dir := ./lib
comm_dirstr := ${src_dir}/communication
mngt_dirstr := ${src_dir}/management
proc_dirstr := ${src_dir}/processing
#----------------------------- DPU Codes --------------------------------------
DPU_SRCS := ${src_dir}/Parallel.c ${src_dir}/Table.c ${src_dir}/TableShared.c 
DPU_SRCS += ${mngt_dirstr}/SmallTableInit_dpu.c
DPU_SRCS += ${proc_dirstr}/gen_red/gen_red_dpu.c ${proc_dirstr}/map/map_dpu.c \
					${proc_dirstr}/zip/zip_dpu.c ${proc_dirstr}/zip/ZipProcessing.c
DPU_SRCS += ${proc_dirstr}/ProcessingHelper.c
#----------------------------- CPU Codes --------------------------------------
CPU_SRCS := ${src_dir}/Common.c ${src_dir}/TableHost.c ${src_dir}/UpmemCustom.c 
CPU_SRCS += ${comm_dirstr}/CommHelper.c ${comm_dirstr}/CommOps.c
CPU_SRCS += ${mngt_dirstr}/Management.c ${mngt_dirstr}/SmallTableInit.c
CPU_SRCS += ${proc_dirstr}/gen_red/GenRed.c ${proc_dirstr}/map/Map.c ${proc_dirstr}/zip/Zip.c 
CPU_SRCS += ${proc_dirstr}/ProcessingHelperHost.c

#---------------------------- Compiler setups ----------------------------------
DPU_COMPILER := dpu-upmem-dpurte-clang
DPU_FLAGS := -O2 -DNR_TASKLETS=12 -I./
HOST_C_COMPILER := gcc


dpu: ${DPU_SRCS}
	@mkdir -p ${DPU_BIN_DIR}
	${DPU_COMPILER} ${DPU_SRCS} -fPIC -shared -o ${DPU_BIN_DIR}/dpu.so

host: ${CPU_SRCS}
	@mkdir -p ${CPU_BIN_DIR}
	${CPU_COMPILER} ${CPU_SRCS} -fPIC -shared -o ${CPU_BIN_DIR}/cpu.so