import * as vscode from 'vscode';
import * as fs from 'fs';
import * as path from 'path';

// Este metodo se llama cuando la extension se activa
export function activate(context: vscode.ExtensionContext) {
	console.log('Congratulations, your extension "memorymanager" is now active!');

	// Comando para que la extension empiece a funcionar
	let disposable = vscode.commands.registerCommand('memorymanager.activarExtension', async () => {

		// Input "booleano" donde el usuario decide si usar o no un servidor remoto
		const result = await vscode.window.showQuickPick(['Si','No'],
		{
			placeHolder: 'Desea utilizar un servidor remoto?',
			
			//onDidSelectItem: item => vscode.window.showInformationMessage(`Focus ${++i}: ${item}`)
		});
		// Si el usuario desea utilizar servidor remoto se procede a solicitar: IP/puerto/password
		if (result === 'Si'){
			const ip = await vscode.window.showInputBox({
				value: 'Digite el ip del servidor que desea acceder'
			});
			const puerto = await vscode.window.showInputBox({
				value: 'Digite el puerto del servidor'
			});
			const password = await vscode.window.showInputBox({
				value: 'Digite el password del servidor'
			});
		//Si el usuario no utiliza el servidor remoto simplemente se muestra el heap visualizer	
		} else {
			vscode.window.showInformationMessage('El usuario no desea utilizar un servidor remoto');
		}
		let jsonFile = [ 
            { "ID": "1", "value":"44", "type":"int", "address":"00x55", "ref":"7"}, 
            { "ID": "1", "value":"44", "type":"int", "address":"00x55", "ref":"7"}, 
			{ "ID": "1", "value":"44", "type":"int", "address":"00x55", "ref":"7"},
			{ "ID": "1", "value":"44", "type":"int", "address":"00x55", "ref":"7"},
			{ "ID": "1", "value":"44", "type":"int", "address":"00x55", "ref":"7"}   
		]; 
		// json con todos los datos a mostrar en el heapvisualizer
		const htmlTable = jsonFile.reduce((acc : any , data : any) => {
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
				${ htmlTable }
	  		</table>
		</body>
		</html>`;

		// Webview
		const panel = vscode.window.createWebviewPanel(
			'heapVisualizer',
			'Heap Visualizer',
			vscode.ViewColumn.One,
			{}
		  );
		// @ts-ignore
		panel.webview.html = webviewHtml;
	});

	context.subscriptions.push(disposable);
}

// this method is called when your extension is deactivated
export function deactivate() {}
