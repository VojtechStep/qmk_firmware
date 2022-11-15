let
  sources = import ./util/nix/sources.nix;
  nixpkgs = import sources.nixpkgs { };
in
(import ./shell.nix { arm = false; }).overrideAttrs
  (oldAttrs: {
    nativeBuildInputs = oldAttrs.nativeBuildInputs ++ [ nixpkgs.wally-cli ];
  })
