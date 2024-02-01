{
  description = "fox32 tools";

  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (sys:
      let pkgs = import nixpkgs { system = sys; };
      in rec {
        packages.gfx2inc = pkgs.rustPlatform.buildRustPackage rec {
          pname = "gfx2inc";
          version = "0.1.0";

          src = ./gfx2inc;
          cargoLock = { lockFile = ./gfx2inc/Cargo.lock; };

          NIX_SEMVER = version;
          NIX_GIT_SHA_SHORT = if self ? rev then builtins.substring 0 7 self.rev else "dirty";
        };
        packages.default = packages.gfx2inc;

        devShells.default = pkgs.mkShell {
          packages = [ pkgs.cargo ];
        };

      }
    );
}
