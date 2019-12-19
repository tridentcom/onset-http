# Tridentcom Onset HTTP
> Fast and easy to use HTTP requests for Onset.
## How to install

> Download the precompiled .so file from the ***Releases*** tab and add it to your
 plugins folder.
 
 > Add onset-http to the plugins section in your server_config.json
## Functions

```lua
-- Starts HTTP Get requests with provided parameters.
local url = "https://example.com"
local parameters = "data=test" -- Url Paramter Format (Tables Soon)
httpGet(url, parameters, function(body, code, lenght)
	print(body) -- Response body.
	print(code) -- Response code.
	print(length) -- Length of response.
end)
```

```lua
-- Starts HTTP Post requests with provided parameters.
local url = "https://example.com"
httpGet(url, function(body, code, lenght)
	print(body) -- Response body.
	print(code) -- Response code.
	print(length) -- Length of response.
end)
```

## Credits
Created by NERO2k.

Code extracted and repackaged from Tridentcom Ares for Onset.
