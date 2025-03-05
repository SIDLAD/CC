function getWeather(): Promise<string> {
    return new Promise(function(resolve, reject) {
        reject('Sunny')
    })
}

function onSuccess(data: string): void {
    console.log(`First param ${data}`)
}

function onError(error: string): void {
    console.log(`Error: ${error}`)
}

getWeather().then(onSuccess, onError)