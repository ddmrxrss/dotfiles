local keymap = vim.keymap.set
local saga = require('lspsaga')

saga.init_lsp_saga()

keymap({"n","v"}, "<leader>ca", "<cmd>Lspsaga code_action<CR>", { silent = true })

keymap("n", "<leader>cd", "<cmd>Lspsaga show_line_diagnostics<CR>", { silent = true })
