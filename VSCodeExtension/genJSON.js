
const ffi = require("ffi-napi");
	const libCPP = new ffi.Library("/home/parallels/Desktop/VSCodeMemoryManager/CPP/cmake-build-debug/libCPP", {
		"salida": [
			"int", []
		],
	});
libCPP.salida();

