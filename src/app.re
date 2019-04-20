open Tea.App;
open Tea.Html;

[@bs.deriving {accessors: accessors}]
type msg =
  | Increment
  | Decrement
  | Set(int);

type state = {count: int};

let init = () => {count: 0};

let update = model =>
  fun
  | Increment => {count: model.count + 1}
  | Decrement => {count: model.count - 1}
  | Set(v) => {count: v};

let view_button = (title: string, message: msg) =>
  <button onClick={_ => Some(message)}> {text(title)} </button>;

let view = model =>
  <div>
    <span style=[("text-weight", "bold")]>
      {text(string_of_int(model.count))}
    </span>
    <br />
    {view_button("Increment", Increment)}
    <br />
    {view_button("Decrement", Decrement)}
    <br />
    {if (model.count != 0) {
       view_button("Reset", Set(0));
     } else {
       noNode;
     }}
  </div>;

let main = beginnerProgram({model: init(), update, view});
