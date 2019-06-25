open Helpers;

[@react.component]
let make = () => {
  <div>
      <h1 className="title">
        (toString("File Browser"))
      </h1>
      <FileBrowser/>
  </div>
};
