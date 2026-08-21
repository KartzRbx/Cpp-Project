const { spawnSync, spawn } = require("child_process");
const path = require("path");

const root = path.resolve(__dirname, "..");
const exe = path.join(root, "cmake-build", "EstudoCpp.exe");

process.env.Path = [
  "C:\\Program Files\\CMake\\bin",
  "C:\\msys64\\ucrt64\\bin",
  process.env.Path || "",
].join(";");

function build() {
  const result = spawnSync(
    "cmake",
    ["--build", "cmake-build", "-j", "4"],
    { cwd: root, stdio: "inherit", shell: true }
  );

  if (result.status !== 0) {
    process.exit(result.status ?? 1);
  }
}

function start() {
  const child = spawn(exe, [], {
    cwd: root,
    stdio: "inherit",
    shell: true,
  });

  child.on("exit", (code) => process.exit(code ?? 0));
}

const cmd = process.argv[2] || "dev";

if (cmd === "build") {
  build();
} else if (cmd === "start") {
  start();
} else if (cmd === "dev") {
  build();
  start();
} else {
  console.error(`Comando desconhecido: ${cmd}`);
  console.error("Use: build | start | dev");
  process.exit(1);
}
