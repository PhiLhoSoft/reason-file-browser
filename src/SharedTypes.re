type file = {
  id: string,
  parentId: string, // Empty string on root
  name: string,
  contentType: string,
  isDir: bool,
  size: int,
  timeCreation: int,
  timeLastModification: int,
};

type tree =
  | Leaf(file)
  | Branch(treeBranch)
and treeBranch = {
  folder: file,
  parent: treeBranch,
  children: list(tree),
  expanded: bool,
};

type state = {
  tree: tree,
  status: string,
};

type action =
  | Delete(list(file))
  | Move(list(file), file)
  | Copy(list(file), file)
  ;
