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
// Este metodo se llama cuando la extension se activa
function activate(context) {
    console.log('Congratulations, your extension "memorymanager" is now active!');
    // Comando para que la extension empiece a funcionar
    let disposable = vscode.commands.registerCommand('memorymanager.activarExtension', () => __awaiter(this, void 0, void 0, function* () {
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
            const password = yield vscode.window.showInputBox({
                value: 'Digite el password del servidor'
            });
            //Si el usuario no utiliza el servidor remoto simplemente se muestra el heap visualizer	
        }
        else {
            vscode.window.showInformationMessage('El usuario no desea utilizar un servidor remoto');
        }
        let jsonFile = { VSPtr: [
                { "ID": "1", "value": "44", "type": "int", "address": "dsdf", "ref": "7" },
                { "ID": "1", "value": "44", "type": "int", "address": "sdf", "ref": "7" },
                { "ID": "1", "value": "44", "type": "int", "address": "sdf", "ref": "7" },
                { "ID": "1", "value": "44", "type": "int", "address": "sdf", "ref": "7" },
                { "ID": "1", "value": "44", "type": "int", "address": "sdf", "ref": "7" }
            ] };
        // json con todos los datos a mostrar en el heapvisualizer
        const htmlTable = jsonFile.VSPtr.reduce((acc, data) => {
            return `
				${acc}
					<tr>
						<td>${data.ID}</td>
						<td>${data.value}</td>
						<td>${data.type}</td>
						<td>${data.adress}</td>
						<td>${data.ref}</td>
					</tr>
			
			`;
        }, '');
        // codigo en htm que se usa para visualizar el heap visualizer mediante un Webview
        let webviewHtml = `<!DOCTYPE html>
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
					<th>ID</th>
					<th>value</th>
					<th>type</th>
					<th>address</th>
					<th>#ref</th>
					
				</tr>
				${htmlTable}
	  		</table>
		</body>
		</html>`;
        // Webview
        const panel = vscode.window.createWebviewPanel('heapVisualizer', 'Heap Visualizer', vscode.ViewColumn.One, {});
        // @ts-ignore
        panel.webview.html = webviewHtml;
    }));
    context.subscriptions.push(disposable);
}
exports.activate = activate;
// this method is called when your extension is deactivated
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map