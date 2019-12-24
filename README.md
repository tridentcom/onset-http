# Tridentcom Onset HTTP
> Fast and easy to use HTTP requests for Onset.
## How to install

> Download the precompiled .so file from the ***Releases*** tab and add it to your
 plugins folder.
 
 > Add onset-http to the plugins section in your server_config.json
## Functions

```lua
-- Starts HTTP Get request with provided parameters.
local url = "https://example.com"
httpGet(url, function(body, code, lenght)
	print(body) -- Response body.
	print(code) -- Response code.
	print(length) -- Length of response.
end)
```

```lua
-- Starts HTTP Post request with provided parameters.
local url = "https://example.com"
local parameters = "data=test" -- Url Paramter Format (Tables Soon)
httpPost(url, parameters, function(body, code, lenght)
	print(body) -- Response body.
	print(code) -- Response code.
	print(length) -- Length of response.
end)
```

## Disclaimer
This plugin is currently blocking. This means that an HTTP request will halt your servers Lua execution until the request has been sent and data has been received. Several mitigation factors exist. Such as using separate detached threads or thread pooling. I'm relatively new to c++ and even more so c++ in Lua so feel free to make a pull request with a solution. The furthest I have come is mitigating the blocking issue but the Lua state gets wiped for some unknown reason making me unable to callback to the included function. For more details or advice feel free to message me on discord @NERO2k#0001

If I have some eureka moment I will update this package but currently, I have not got time to actively pursue a fix for this issue nor do I have the need for this package anymore due to some reworks and the change to handle all requests internally for my own project.

## Credits
Created by NERO2k.

Code extracted and repackaged from Tridentcom Ares for Onset.
