open SharedTypes;

let initialState: state = {
  tree: Leaf({ id: "root", parentId: "", name: "Root", contentType: "application/vnd.pls.folder.root", isDir: true, size: 0, timeCreation: 0, timeLastModification: 0 }),
  status: "initializing",
};

let noop = (state: state) => state;

let reducer = (state: state, action: action) =>
  switch (action) {
  | Delete(_fileList) => noop(state)
  | Move(_fileList, _folder) => noop(state)
  | Copy(_fileList, _folder) => noop(state)
  };

[@react.component]
let make = () => {
  let (initialState, _setInitialState) = React.useState(() => initialState);
  let (state, _dispatch) = React.useReducer(reducer, initialState);

  <div className="file-browser">
    <Tree state/>
  </div>;
};
