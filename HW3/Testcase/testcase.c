uint32_t ext_dsp_codegen(uint32_t a, uint32_t b);
uint32_t ext_dsp_codegen(uint32_t a, uint32_t b) {
	uint32_t c = __rv__ukadd8(a, b);
	uint32_t x = __rv__cmpeq8(a, c);
	uint32_t y = __rv__ucmplt8(b, c);
	return __rv__uksub8(x, y);
}
