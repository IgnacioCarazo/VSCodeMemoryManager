"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const vscode = require("vscode");
const fs = require("fs");
const path = require("path");
function getWebviewContent(jsonFile) {
    // json con todos los datos a mostrar en el heapvisualizer
    const htmlTable = jsonFile.reduce((acc, data) => {
        return `
				${acc}
					<tr>
						<td>${data.address}</td>
						<td>${data.id}</td>
						<td>${data.ref}</td>
						<td>${data.size}</td>
						<td>${data.type}</td>
						
					</tr>
			
			`;
    }, '');
    // codigo en htm que se usa para visualizar el heap visualizer mediante un Webview
    return `<!DOCTYPE html>
		<html lang="en">
		<head>
			<meta charset="UTF-8">
			<style>
			table {
				border-collapse: collapse;
			  }
			table, th, td {
				border: 1px solid white;
			}
			</style>
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<title>Heap Visualizer</title>
		</head>
		<body>
			<table style="width:100%">
				<tr>
					<th>address</th>
					<th>ID</th>
					<th>#ref</th>
					<th>value</th>
					<th>type</th>
					
					
				</tr>
				${htmlTable}
	  		</table>
		</body>
		</html>`;
}
// Este metodo se llama cuando la extension se activa
function activate(context) {
    // crea el Webview donde se visualiza el heap visualizer
    const panel = vscode.window.createWebviewPanel('heapVisualizer', 'Heap Visualizer', vscode.ViewColumn.One, {});
    // Comando para que la extension empiece a funcionar
    let disposable = vscode.commands.registerCommand('vscodeextension.activarExtension', () => __awaiter(this, void 0, void 0, function* () {
        const ffi = require("ffi-napi");
        const libCPP = new ffi.Library("/home/parallels/Desktop/VSCodeMemoryManager/CPP/cmake-build-debug/libCPP", {
            "salida": [
                "int", []
            ],
        });
        libCPP.salida();
        // archivos json con la informacion del heap visualizer  
        let jsonFile1 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON0.json'), 'utf8'));
        let jsonFile2 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON1.json'), 'utf8'));
        let jsonFile3 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON2.json'), 'utf8'));
        let jsonFile4 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON3.json'), 'utf8'));
        let jsonFile5 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON4.json'), 'utf8'));
        let jsonFile6 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON5.json'), 'utf8'));
        let jsonFile7 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON6.json'), 'utf8'));
        let jsonFile8 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON7.json'), 'utf8'));
        let jsonFile9 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON8.json'), 'utf8'));
        let jsonFile10 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON9.json'), 'utf8'));
        let jsonFile11 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON10.json'), 'utf8'));
        let jsonFile12 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON11.json'), 'utf8'));
        let jsonFile13 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON12.json'), 'utf8'));
        let jsonFile14 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON13.json'), 'utf8'));
        let jsonFile15 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON14.json'), 'utf8'));
        let jsonFile16 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON15.json'), 'utf8'));
        let jsonFile17 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON16.json'), 'utf8'));
        let jsonFile18 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON17.json'), 'utf8'));
        let jsonFile19 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON18.json'), 'utf8'));
        let jsonFile20 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON19.json'), 'utf8'));
        let jsonFile21 = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../JACKSON20.json'), 'utf8'));
        var jsonFiles = [jsonFile1, jsonFile2, jsonFile3, jsonFile4, jsonFile5, jsonFile6, jsonFile7, jsonFile8, jsonFile9, jsonFile10,
            jsonFile11, jsonFile12, jsonFile13, jsonFile14, jsonFile15, jsonFile16, jsonFile17, jsonFile18, jsonFile19, jsonFile20, jsonFile21];
        // Input "booleano" donde el usuario decide si usar o no un servidor remoto
        const result = yield vscode.window.showQuickPick(['Si', 'No'], {
            placeHolder: 'Desea utilizar un servidor remoto?',
        });
        // Si el usuario desea utilizar servidor remoto se procede a solicitar: IP/puerto/password
        if (result === 'Si') {
            const ip = yield vscode.window.showInputBox({
                value: 'Digite el ip del servidor que desea acceder'
            });
            const puerto = yield vscode.window.showInputBox({
                value: 'Digite el puerto del servidor'
            });
            const passWord = yield vscode.window.showInputBox({
                password: true,
                placeHolder: 'Digite el password del servidor',
                value: ''
            });
            // Conexion al servidor
            var net = require('net');
            var client = new net.Socket();
            client.connect(puerto, ip, function () {
                client.write(passWord);
                client.on('data', function (data) {
                    vscode.window.showInformationMessage('Received: ' + data);
                });
            });
            //Si el usuario no utiliza el servidor remoto simplemente se muestra el heap visualizer	
        }
        else {
            vscode.window.showInformationMessage('El usuario no desea utilizar un servidor remoto');
        }
        var index = 0;
        const updateWebview = () => {
            panel.webview.html = getWebviewContent(jsonFiles[index]);
            index++;
            console.log(index);
        };
        console.log(jsonFiles.length);
        // Set initial content
        updateWebview();
        // And schedule updates to the content every second
        setInterval(updateWebview, 3000);
    }));
    context.subscriptions.push(disposable);
}
exports.activate = activate;
// this method is called when your extension is deactivated
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map