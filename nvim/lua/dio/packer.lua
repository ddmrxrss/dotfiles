vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
	-- packer
	use 'wbthomason/packer.nvim'

    -- lsp zero
    use {
        'VonHeikemen/lsp-zero.nvim',
        requires = {
            -- LSP Support
            {'neovim/nvim-lspconfig'},             -- Required
            {'williamboman/mason.nvim'},           -- Optional
            {'williamboman/mason-lspconfig.nvim'}, -- Optional

            -- Autocompletion
            {'hrsh7th/nvim-cmp'},         -- Required
            {'hrsh7th/cmp-nvim-lsp'},     -- Required
            {'hrsh7th/cmp-buffer'},       -- Optional
            {'hrsh7th/cmp-path'},         -- Optional
            {'saadparwaiz1/cmp_luasnip'}, -- Optional
            {'hrsh7th/cmp-nvim-lua'},     -- Optional

            -- Snippets
            {'L3MON4D3/LuaSnip'},             -- Required
            {'rafamadriz/friendly-snippets'}, -- Optional
        }
    }

	-- telescope
	use {
		'nvim-telescope/telescope.nvim', tag = '0.1.1',
		requires = { {'nvim-lua/plenary.nvim'} }
	}

	-- catppuccin
	use { "catppuccin/nvim", as = "catppuccin", config = function ()
        --		vim.cmd("colorscheme catppuccin-mocha")
		end
	}

    -- tokyo-night
    use 'folke/tokyonight.nvim'

    -- rose-pine
    use({ 'rose-pine/neovim', as = 'rose-pine' })

    vim.cmd('colorscheme rose-pine')

	-- treesitter
	use {'nvim-treesitter/nvim-treesitter', run = ':TSUpdate' }

    -- alpha
    use {
        'goolord/alpha-nvim',
        requires = { 'nvim-tree/nvim-web-devicons' },
    }

    -- colorizer
    use 'norcalli/nvim-colorizer.lua'

    -- autopairs
    use {
        "windwp/nvim-autopairs",
        config = function() require("nvim-autopairs").setup {} end
    }

    -- comment
    use {
        'numToStr/Comment.nvim',
        config = function()
            require('Comment').setup({ toggler = { line = "<leader>/" } })
        end
    }

    -- gitsigns
    use {
        'lewis6991/gitsigns.nvim',
        config = function()
            require('gitsigns').setup()
        end
    }

    -- lualine
    use {
        'nvim-lualine/lualine.nvim',
        requires = { 'kyazdani42/nvim-web-devicons', opt = true }
    }

    -- html autopairs
    use 'windwp/nvim-ts-autotag'

    -- lspkind nvim 
    use 'onsails/lspkind.nvim'

end)
