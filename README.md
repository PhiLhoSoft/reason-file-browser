# A file browser with ReasonML and ReasonReact

## About

A file browser similar to the one in Visual Studio Code, for example.
Theme chosen because Reason is good at handling recursive structures, so it can shine in this project.
As it runs in a browser, it doesn't read the file system, it reads a Json file describing a directory structure instead.

Based on structure generated with `bsb -init file-browser -theme react-hooks`.
In bsconfig.json, I changed the field "in-source" from true to false. This outputs compiled JavaScript (*.bs.js) into the lib/js directory instead of leaving them spread all over the root src directory.
Also had to change `entry` to `./lib/js/src/Index.bs.js`,

## Run Project

```sh
npm install
# build in watch mode
npm start
# in another tab, build the webapp in watch mode
npm run webpack
# open build/index.html
```

After you see the Webpack compilation succeed (the `npm run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Run Project with Server

To run with the Webpack development server run `npm run server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

Note that any hot reload on a route will fall back to the root (`/`), so `ReasonReact.Router.dangerouslyGetInitialUrl` will likely be needed alongside the `ReasonReact.Router.watchUrl` logic to handle routing correctly on hot reload refreshes or simply opening the app at a URL that is not the root.

To use a port other than 8000 set the `PORT` environment variable (`cross-env PORT=8080 npm run server`).

## Build for Production

```sh
npm run clean
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version. You can then deploy the contents of the `build` directory (`index.html`, `index.css` and `Index.js`).

If you make use of routing (via `ReasonReact.Router` or similar logic) ensure that server-side routing handles your routes or that 404's are directed back to `index.html` (which is how the dev server is set up).

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
