open SharedTypes;
open Helpers;

[@react.component]
let make = (~state: state) => {
  <div className="tree">
    (
      state.status |> toString
    )
    <div className="status">
      (
        state.status |> toString
      )
    </div>
  </div>
};
